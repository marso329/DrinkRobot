cd /home/martin/repositories/DrinkRobot
git add *
git commit -a -m "test"
git push
ssh pi@192.168.43.208 /home/pi/scripts/start.sh
