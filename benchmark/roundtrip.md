# Testing the speed of nycflights roundtrip


nycflights round trip is an example in the `writexl` documentation. The
original code looks like so:

``` r
library(nycflights13)
out <- readxl::read_xlsx(writexl::write_xlsx(flights))
all.equal(out, flights)
```

Let’s break it down

``` r
date()
```

    [1] "Tue Jun  4 18:38:20 2024"

``` r
library(nycflights13)
system.time(path <- writexl::write_xlsx(flights))
```

       user  system elapsed 
      6.136   0.240   6.386 

``` r
system.time(out <- readxl::read_xlsx(path))
```

       user  system elapsed 
      2.280   0.588   2.877 

``` r
all.equal(out, flights)
```

    [1] "Component \"time_hour\": 'tzone' attributes are inconsistent ('UTC' and 'America/New_York')"

The ODS version

``` r
devtools::load_all()
```

    ℹ Loading readODS
    ℹ Re-compiling readODS (debug build)

    ── R CMD INSTALL ───────────────────────────────────────────────────────────────
    * installing *source* package ‘readODS’ ...
    ** using staged installation
    ** libs
    using C++ compiler: ‘g++ (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0’
    make[1]: Entering directory '/home/chainsawriot/dev/readODS/src'
    make[1]: Leaving directory '/home/chainsawriot/dev/readODS/src'
    make[1]: Entering directory '/home/chainsawriot/dev/readODS/src'
    g++ -std=gnu++17 -I"/usr/share/R/include" -DNDEBUG -I../inst/include      -fpic  -g -O2 -ffile-prefix-map=/build/r-base-H8urij/r-base-4.4.0=. -fstack-protector-strong -Wformat -Werror=format-security -Wdate-time -D_FORTIFY_SOURCE=2  -UNDEBUG -Wall -pedantic -g -O0  -c cpp11.cpp -o cpp11.o
    g++ -std=gnu++17 -I"/usr/share/R/include" -DNDEBUG -I../inst/include      -fpic  -g -O2 -ffile-prefix-map=/build/r-base-H8urij/r-base-4.4.0=. -fstack-protector-strong -Wformat -Werror=format-security -Wdate-time -D_FORTIFY_SOURCE=2  -UNDEBUG -Wall -pedantic -g -O0  -c get_sheet_names.cpp -o get_sheet_names.o
    g++ -std=gnu++17 -I"/usr/share/R/include" -DNDEBUG -I../inst/include      -fpic  -g -O2 -ffile-prefix-map=/build/r-base-H8urij/r-base-4.4.0=. -fstack-protector-strong -Wformat -Werror=format-security -Wdate-time -D_FORTIFY_SOURCE=2  -UNDEBUG -Wall -pedantic -g -O0  -c is_ods.cpp -o is_ods.o
    g++ -std=gnu++17 -I"/usr/share/R/include" -DNDEBUG -I../inst/include      -fpic  -g -O2 -ffile-prefix-map=/build/r-base-H8urij/r-base-4.4.0=. -fstack-protector-strong -Wformat -Werror=format-security -Wdate-time -D_FORTIFY_SOURCE=2  -UNDEBUG -Wall -pedantic -g -O0  -c read_flat_ods_.cpp -o read_flat_ods_.o
    g++ -std=gnu++17 -I"/usr/share/R/include" -DNDEBUG -I../inst/include      -fpic  -g -O2 -ffile-prefix-map=/build/r-base-H8urij/r-base-4.4.0=. -fstack-protector-strong -Wformat -Werror=format-security -Wdate-time -D_FORTIFY_SOURCE=2  -UNDEBUG -Wall -pedantic -g -O0  -c read_ods_.cpp -o read_ods_.o
    g++ -std=gnu++17 -I"/usr/share/R/include" -DNDEBUG -I../inst/include      -fpic  -g -O2 -ffile-prefix-map=/build/r-base-H8urij/r-base-4.4.0=. -fstack-protector-strong -Wformat -Werror=format-security -Wdate-time -D_FORTIFY_SOURCE=2  -UNDEBUG -Wall -pedantic -g -O0  -c read_ods_internals.cpp -o read_ods_internals.o
    g++ -std=gnu++17 -I"/usr/share/R/include" -DNDEBUG -I../inst/include      -fpic  -g -O2 -ffile-prefix-map=/build/r-base-H8urij/r-base-4.4.0=. -fstack-protector-strong -Wformat -Werror=format-security -Wdate-time -D_FORTIFY_SOURCE=2  -UNDEBUG -Wall -pedantic -g -O0  -c splice.cpp -o splice.o
    g++ -std=gnu++17 -I"/usr/share/R/include" -DNDEBUG -I../inst/include      -fpic  -g -O2 -ffile-prefix-map=/build/r-base-H8urij/r-base-4.4.0=. -fstack-protector-strong -Wformat -Werror=format-security -Wdate-time -D_FORTIFY_SOURCE=2  -UNDEBUG -Wall -pedantic -g -O0  -c write_sheet_file_.cpp -o write_sheet_file_.o
    g++ -std=gnu++17 -shared -L/usr/lib/R/lib -Wl,-Bsymbolic-functions -flto=auto -ffat-lto-objects -flto=auto -Wl,-z,relro -o readODS.so cpp11.o get_sheet_names.o is_ods.o read_flat_ods_.o read_ods_.o read_ods_internals.o splice.o write_sheet_file_.o -L/usr/lib/R/lib -lR
    make[1]: Leaving directory '/home/chainsawriot/dev/readODS/src'
    installing to /tmp/RtmpBw5a9V/devtools_install_3c7146ca2cbc6/00LOCK-readODS/00new/readODS/libs
    ** checking absolute paths in shared objects and dynamic libraries
    * DONE (readODS)

``` r
system.time(path <- readODS::write_ods(flights))
```

       user  system elapsed 
     13.219   0.480  13.910 

``` r
system.time(out <- readODS::read_ods(path))
```

       user  system elapsed 
     27.063   1.952  29.042 

``` r
all.equal(out, flights)
```

    [1] "Component \"time_hour\": 'tzone' attributes are inconsistent ('UTC' and 'America/New_York')"
    [2] "Component \"time_hour\": Mean absolute difference: 15618.15"                                

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
    [1] readODS_2.3.1      testthat_3.2.1     nycflights13_1.0.2

    loaded via a namespace (and not attached):
     [1] utf8_1.2.4        stringi_1.8.4     digest_0.6.35     magrittr_2.0.3   
     [5] evaluate_0.23     pkgload_1.3.4     fastmap_1.1.1     cellranger_1.1.0 
     [9] rprojroot_2.0.4   jsonlite_1.8.8    zip_2.3.1         processx_3.8.4   
    [13] writexl_1.5.0     pkgbuild_1.4.4    sessioninfo_1.2.2 brio_1.1.4       
    [17] ps_1.7.6          urlchecker_1.0.1  promises_1.3.0    purrr_1.0.2      
    [21] fansi_1.0.6       cli_3.6.2         shiny_1.8.1.1     rlang_1.1.4      
    [25] ellipsis_0.3.2    withr_3.0.0       remotes_2.5.0     cachem_1.0.8     
    [29] yaml_2.3.8        devtools_2.4.5    tools_4.4.0       tzdb_0.4.0       
    [33] memoise_2.0.1     httpuv_1.6.15     vctrs_0.6.5       R6_2.5.1         
    [37] mime_0.12         lifecycle_1.0.4   minty_0.0.1       stringr_1.5.1    
    [41] fs_1.6.3          htmlwidgets_1.6.4 usethis_2.2.3     miniUI_0.1.1.1   
    [45] callr_3.7.6       desc_1.4.3        pkgconfig_2.0.3   pillar_1.9.0     
    [49] later_1.3.2       glue_1.7.0        profvis_0.3.8     Rcpp_1.0.12      
    [53] xfun_0.43         tibble_3.2.1      rstudioapi_0.16.0 knitr_1.46       
    [57] xtable_1.8-4      htmltools_0.5.8.1 rmarkdown_2.26    compiler_4.4.0   
    [61] readxl_1.4.3     
