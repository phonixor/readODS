prefixes <- c("HEAD", "PR")

## TODO: make this a GH comment

for (prefix in prefixes) {
    print(head)
    print(readRDS("benchmark/", prefix, "_write_ods_.RDS"))
}
