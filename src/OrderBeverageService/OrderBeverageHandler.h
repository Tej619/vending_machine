#ifndef VENDING_MACHINE_MICROSERVICES_ORDERBEVERAGEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_ORDERBEVERAGEHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/OrderBeverageService.h"
#include "../../gen-cpp/WeatherService.h"
#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine
{

    class OrderBeverageServiceHandler : public OrderBeverageServiceIf
    {
    public:
        OrderBeverageServiceHandler(
            ClientPool<ThriftClient<WeatherServiceClient>> *weather_client_pool,
            ClientPool<ThriftClient<BeveragePreferenceServiceClient>> *beverage_client_pool);
        ~OrderBeverageServiceHandler() override = default;

        void PlaceOrder(std::string &_return, const int64_t city) override;

    private:
        ClientPool<ThriftClient<WeatherServiceClient>> *_weather_client_pool;
        ClientPool<ThriftClient<BeveragePreferenceServiceClient>> *_beverage_client_pool;
    };

    // Constructor
    OrderBeverageServiceHandler::OrderBeverageServiceHandler(
        ClientPool<ThriftClient<WeatherServiceClient>> *weather_client_pool,
        ClientPool<ThriftClient<BeveragePreferenceServiceClient>> *beverage_client_pool)
    {
        // Storing the clientpool for weather and beverage
        _weather_client_pool = weather_client_pool;
        _beverage_client_pool = beverage_client_pool;
    }

    // Remote Procedure "PlaceOrder"
    void OrderBeverageServiceHandler::PlaceOrder(std::string &_return, const int64_t city)
    {
        // 1. Get the weather service client pool
        auto weather_client_wrapper = _weather_client_pool->Pop();
        if (!weather_client_wrapper)
        {
            ServiceException se;
            se.errorCode = ErrorCode::SE_THRIFT_CONN_ERROR;
            se.message = "Failed to connect to weather-service";
            throw se;
        }
        auto weather_client = weather_client_wrapper->GetClient();

        // 2. Get the beverage service client pool
        auto beverage_client_wrapper = _beverage_client_pool->Pop();
        if (!beverage_client_wrapper)
        {
            ServiceException se;
            se.errorCode = ErrorCode::SE_THRIFT_CONN_ERROR;
            se.message = "Failed to connect to beverage-preference-service";
            throw se;
        }
        auto beverage_client = beverage_client_wrapper->GetClient();

        // by default get cold
        WeatherType::type weatherType = WeatherType::type::COLD;

        // 3. call the remote procedure : GetWeather
        try
        {
            weatherType = weather_client->GetWeather(city);
        }
        catch (...)
        {
            _weather_client_pool->Push(weather_client_wrapper);
            LOG(error) << "Failed to send call GetWeather to weather-client";
            throw;
        }
        _weather_client_pool->Push(weather_client_wrapper);

        // 4. Get beverage preference based on weather type WARM and HOT
        std::string beverage;
        BeverageType::type beverage_type = (weatherType == WeatherType::type::WARM) ? BeverageType::COLD : BeverageType::HOT;

        try
        {
            beverage_client->getBeverage(beverage, beverage_type);
        }
        catch (...)
        {
            _beverage_client_pool->Push(beverage_client_wrapper);
            LOG(error) << "Failed to get beverage from beverage-client";
            throw;
        }
        _beverage_client_pool->Push(beverage_client_wrapper);

        std::string weather_str = (weatherType == WeatherType::type::WARM) ? "Warm" : "Cold";
        std::string beverage_type_str = (beverage_type == BeverageType::HOT) ? "Hot" : "Cold";
        _return = beverage_type_str + " for Weather " + weather_str + " for city " + std::to_string(city) + " and beverage is " + beverage;
    }

} // namespace vending_machine

#endif // VENDING_MACHINE_MICROSERVICES_ORDERBEVERAGEHANDLER_H