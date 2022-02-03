#!/bin/bash
for i in {1..4}
do
  ./maintenance< test$i.in > tmp.out
  diff tmp.out test$i.out
done

rm -f tmp.out
