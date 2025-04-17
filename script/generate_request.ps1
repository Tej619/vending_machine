# for i in `seq 100`
# do
# 	curl -d "city_id="$i http://127.0.0.1:8081/
# done

for ($i = 1; $i -le 100; $i++) {
    Invoke-WebRequest -Uri "http://127.0.0.1:8081/" -Method POST -Body "city_id=$i"
}