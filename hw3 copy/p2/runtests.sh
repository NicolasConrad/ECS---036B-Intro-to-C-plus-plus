#!/bin/bash
for i in {1..11}
do
  ./assigntables < test$i.in > test$i.svg
  diff tmp.svg test$i.svg
done

rm -f tmp.out