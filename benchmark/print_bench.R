library(bench)
prefixes <- c("HEAD", "PR")

## TODO: make this a GH comment

for (prefix in prefixes) {
    print(prefix)
    print(readRDS(paste0("benchmark/", prefix, "_write_ods_.RDS"))$median)
}
