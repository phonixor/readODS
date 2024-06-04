# Testing the speed of reading the ODS file `issue81.ods`


``` r
date()
```

    [1] "Tue Jun  4 18:39:24 2024"

``` r
devtools::load_all()
```

    ℹ Loading readODS

``` r
file <- here::here("tests/testdata/issue81.ods")
system.time(x <- read_ods(file, sheet = 2, skip = 4))
```

       user  system elapsed 
      0.407   0.051   0.462 

``` r
dim(x)
```

    [1] 5539   11

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
    [1] readODS_2.3.1  testthat_3.2.1

    loaded via a namespace (and not attached):
     [1] utf8_1.2.4        stringi_1.8.4     digest_0.6.35     magrittr_2.0.3   
     [5] evaluate_0.23     pkgload_1.3.4     fastmap_1.1.1     cellranger_1.1.0 
     [9] rprojroot_2.0.4   jsonlite_1.8.8    zip_2.3.1         pkgbuild_1.4.4   
    [13] sessioninfo_1.2.2 brio_1.1.4        urlchecker_1.0.1  promises_1.3.0   
    [17] purrr_1.0.2       fansi_1.0.6       cli_3.6.2         shiny_1.8.1.1    
    [21] rlang_1.1.4       ellipsis_0.3.2    remotes_2.5.0     withr_3.0.0      
    [25] cachem_1.0.8      yaml_2.3.8        devtools_2.4.5    tools_4.4.0      
    [29] tzdb_0.4.0        memoise_2.0.1     httpuv_1.6.15     here_1.0.1       
    [33] vctrs_0.6.5       R6_2.5.1          mime_0.12         lifecycle_1.0.4  
    [37] minty_0.0.1       stringr_1.5.1     fs_1.6.3          htmlwidgets_1.6.4
    [41] usethis_2.2.3     miniUI_0.1.1.1    pkgconfig_2.0.3   desc_1.4.3       
    [45] pillar_1.9.0      later_1.3.2       glue_1.7.0        profvis_0.3.8    
    [49] Rcpp_1.0.12       xfun_0.43         tibble_3.2.1      rstudioapi_0.16.0
    [53] knitr_1.46        xtable_1.8-4      htmltools_0.5.8.1 rmarkdown_2.26   
    [57] compiler_4.4.0   
