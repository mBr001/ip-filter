#!/bin/bash

cat ip_filter.tsv | ./ip_filter > test.out
md5sum -c sum.md5
