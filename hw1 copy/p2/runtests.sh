for i in {1..15}
do
  echo ======= test$i ======
  ./calculator < test$i.in > t$i.out
  diff t$i.out test$i.out
done
