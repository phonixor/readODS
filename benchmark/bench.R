#!/usr/bin/env Rscript
args <- commandArgs(trailingOnly = TRUE)

saveRDS(bench::mark(readODS::read_ods(readODS::write_ods(nycflights13::flights)), min_iterations = 3), paste0("benchmark/", args[1], "_write_ods_.RDS"))
