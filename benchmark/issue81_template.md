# Testing the speed of reading the ODS file `issue81.ods`

``` r
date()
```

    [1] "Sat Aug 19 00:00:22 2023"

``` r
devtools::load_all()
```

    ℹ Loading readODS

``` r
file <- here::here("tests/testdata/issue81.ods")
system.time(x <- read_ods(file, sheet = 2, skip = 4))
```

       user  system elapsed 
      0.435   0.024   0.459 

``` r
dim(x)
```

    [1] 5539   11

``` r
sessionInfo()
```

    R version 4.3.1 (2023-06-16)
    Platform: x86_64-pc-linux-gnu (64-bit)
    Running under: Ubuntu 22.04.3 LTS

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
    [1] readODS_2.0.1   testthat_3.1.10

    loaded via a namespace (and not attached):
     [1] utf8_1.2.3        xml2_1.3.5        stringi_1.7.12    hms_1.1.3        
     [5] digest_0.6.33     magrittr_2.0.3    evaluate_0.21     pkgload_1.3.2.1  
     [9] fastmap_1.1.1     cellranger_1.1.0  rprojroot_2.0.3   jsonlite_1.8.7   
    [13] zip_2.3.0         processx_3.8.2    pkgbuild_1.4.2    sessioninfo_1.2.2
    [17] brio_1.1.3        urlchecker_1.0.1  ps_1.7.5          promises_1.2.1   
    [21] purrr_1.0.2       fansi_1.0.4       cli_3.6.1         shiny_1.7.5      
    [25] rlang_1.1.1       crayon_1.5.2      ellipsis_0.3.2    remotes_2.4.2.1  
    [29] withr_2.5.0       cachem_1.0.8      yaml_2.3.7        devtools_2.4.5   
    [33] tools_4.3.1       tzdb_0.4.0        memoise_2.0.1     httpuv_1.6.11    
    [37] here_1.0.1        vctrs_0.6.3       R6_2.5.1          mime_0.12        
    [41] lifecycle_1.0.3   stringr_1.5.0     fs_1.6.3          htmlwidgets_1.6.2
    [45] usethis_2.2.2     miniUI_0.1.1.1    pkgconfig_2.0.3   desc_1.4.2       
    [49] callr_3.7.3       pillar_1.9.0      later_1.3.1       glue_1.6.2       
    [53] profvis_0.3.8     Rcpp_1.0.11       xfun_0.40         tibble_3.2.1     
    [57] rstudioapi_0.15.0 knitr_1.43        xtable_1.8-4      htmltools_0.5.6  
    [61] rmarkdown_2.24    readr_2.1.4       compiler_4.3.1    prettyunits_1.1.1
