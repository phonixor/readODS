#!/usr/bin/env Rscript
args <- commandArgs(trailingOnly=TRUE)

saveRDS(bench::mark(readODS::write_ods(nycflights13::flights), min_iterations = 2), paste0("benchmark/", args[1], "_write_ods_.RDS"))
