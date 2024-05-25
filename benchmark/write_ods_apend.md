# Testing the speed of write_ods (append / update)


``` r
date()
```

    [1] "Sun May 26 01:39:19 2024"

``` r
devtools::load_all()
```

    ℹ Loading readODS

``` r
## generate a 3000 x 8 data.frame
set.seed(721831)
df1 <- data.frame(a1 = sample(c(1:100), size = 3000, replace = TRUE),
                  b1 = sample(c(3.14, 3.1416, 12.345, 721.831), size = 3000, replace = TRUE),
                  c1 = sample(LETTERS, size = 3000, replace = TRUE),
                  d1 = sample(c(1L:100L), size = 3000, replace = TRUE),
                  a2 = sample(c(1:100), size = 3000, replace = TRUE),
                  b2 = sample(c(3.14, 3.1416, 12.345, 99.831), size = 3000, replace = TRUE),
                  c2 = sample(LETTERS, size = 3000, replace = TRUE),
                  d2 = sample(c(1L:100L), size = 3000, replace = TRUE))
path <- tempfile(fileext = ".ods")
write_ods(df1, path = path)
system.time(write_ods(df1, path = path, sheet = "aaaa", append = TRUE))
```

       user  system elapsed 
      0.249   0.025   0.280 

``` r
system.time(write_ods(df1, path = path, sheet = "aaaa", update = TRUE))
```

       user  system elapsed 
      0.313   0.035   0.357 

``` r
system.time(write_ods(mtcars, path = path, sheet = "aaaa", update = TRUE))
```

       user  system elapsed 
      0.211   0.028   0.246 

``` r
sessionInfo()
```

    R version 4.4.0 (2024-04-24)
    Platform: x86_64-pc-linux-gnu
    Running under: Ubuntu 22.04.4 LTS

    Matrix products: default
    BLAS:   /usr/lib/x86_64-linux-gnu/blas/libblas.so.3.10.0 
    LAPACK: /usr/lib/x86_64-linux-gnu/lapack/liblapack.so.3.10.0

    locale:
     [1] LC_CTYPE=en_US.UTF-8       LC_NUMERIC=C              
     [3] LC_TIME=en_US.UTF-8        LC_COLLATE=en_US.UTF-8    
     [5] LC_MONETARY=en_US.UTF-8    LC_MESSAGES=en_US.UTF-8   
     [7] LC_PAPER=en_US.UTF-8       LC_NAME=C                 
     [9] LC_ADDRESS=C               LC_TELEPHONE=C            
    [11] LC_MEASUREMENT=en_US.UTF-8 LC_IDENTIFICATION=C       

    time zone: Europe/Berlin
    tzcode source: system (glibc)

    attached base packages:
    [1] stats     graphics  grDevices utils     datasets  methods   base     

    other attached packages:
    [1] readODS_2.2.0.9999 testthat_3.2.1    

    loaded via a namespace (and not attached):
     [1] utf8_1.2.4        stringi_1.8.4     digest_0.6.35     magrittr_2.0.3   
     [5] evaluate_0.23     pkgload_1.3.4     fastmap_1.1.1     cellranger_1.1.0 
     [9] rprojroot_2.0.4   jsonlite_1.8.8    zip_2.3.1         pkgbuild_1.4.4   
    [13] sessioninfo_1.2.2 brio_1.1.4        urlchecker_1.0.1  promises_1.3.0   
    [17] purrr_1.0.2       fansi_1.0.6       cli_3.6.2         shiny_1.8.1.1    
    [21] rlang_1.1.3       ellipsis_0.3.2    remotes_2.5.0     withr_3.0.0      
    [25] cachem_1.0.8      yaml_2.3.8        devtools_2.4.5    tools_4.4.0      
    [29] memoise_2.0.1     httpuv_1.6.15     vctrs_0.6.5       R6_2.5.1         
    [33] mime_0.12         lifecycle_1.0.4   minty_0.0.1       stringr_1.5.1    
    [37] fs_1.6.3          htmlwidgets_1.6.4 usethis_2.2.3     miniUI_0.1.1.1   
    [41] pkgconfig_2.0.3   desc_1.4.3        pillar_1.9.0      later_1.3.2      
    [45] glue_1.7.0        profvis_0.3.8     Rcpp_1.0.12       xfun_0.43        
    [49] tibble_3.2.1      rstudioapi_0.16.0 knitr_1.46        xtable_1.8-4     
    [53] htmltools_0.5.8.1 rmarkdown_2.26    compiler_4.4.0   
