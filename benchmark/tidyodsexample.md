# Benchmarks used in the README of tidyods


``` r
date()
```

    [1] "Sun May 26 01:39:12 2024"

``` r
devtools::load_all()
```

    ℹ Loading readODS

``` r
file <- here::here("benchmark/basic_example.ods")
## it was 50.4ms
bench::mark("readODS" = read_ods(file, sheet = 2), check = FALSE, filter_gc = FALSE, iterations = 20) |>
    dplyr::transmute(expression, min, median, mean = total_time/n_itr, n_itr)
```

    # A tibble: 1 × 4
      expression      min   median     mean
      <bch:expr> <bch:tm> <bch:tm> <bch:tm>
    1 readODS      5.12ms   5.29ms   7.59ms

``` r
postcodes_file <- here::here("benchmark/civil-service-postcodes-2021.ods")
## it was 13.7s
bench::mark("readODS" = readODS::read_ods(postcodes_file, 2), check = FALSE, filter_gc = FALSE, iterations = 5) |>
    dplyr::transmute(expression, min, median, mean = total_time/n_itr, n_itr)
```

    New names:
    New names:
    New names:
    New names:
    New names:
    New names:
    • `` -> `...2`
    • `` -> `...3`
    • `` -> `...4`
    • `` -> `...5`
    • `` -> `...6`
    • `` -> `...7`
    • `` -> `...8`
    • `` -> `...9`
    • `` -> `...10`
    • `` -> `...11`

    # A tibble: 1 × 4
      expression      min   median     mean
      <bch:expr> <bch:tm> <bch:tm> <bch:tm>
    1 readODS       420ms    429ms    435ms
