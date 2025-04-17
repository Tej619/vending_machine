for i in `seq 100`
do
	curl -d "city_id="$i http://127.0.0.1:8081/
done