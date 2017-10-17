#!/bin/bash

for com in $(ls | grep -P '^test_(?!.*\..*)');
do
    ./$com
done
