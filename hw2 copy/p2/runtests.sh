#!/bin/bash
for i in {1..5}
do
  ./assigntables < test$i.in > tmp.out
  diff tmp.out test$i.out
done

rm -f tmp.out
