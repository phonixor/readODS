library(bench)
prefixes <- c("HEAD", "PR")

## TODO: make this a GH comment

for (prefix in prefixes) {
    cat(prefix, "\n")
    cat(readRDS(paste0("benchmark/", prefix, "_write_ods_.RDS"))$median, "\n")
}
