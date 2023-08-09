# readODS 2.0.0

## BREAKING CHANGES: Changed `write_ods(na_as_string)` behaviour

The default for `na_as_string` was `getOption("write_ods_na", default = FALSE)` in v1.8. The default now is `FALSE`, but it writes NA as blank cell (instead of the buggy behaviour of writing NA in the original type, which is rendered as 0 by LibreOffice for numeric types. see #79). This behaviour is compatible with the default of `writexl::write_xlsx`.

The behaviour of `na_as_string = TRUE` is the same as in v1.8: writes NA as string.

## BREAKING CHANGES: Removed `get_num_sheets_in_{f}ods()`

The descendant of `getNrOfSheetsInODS()` is not very useful. If you really need to have the similar function:

```r
length(list_ods_sheets("starwars.ods"))
```

## BREAKING CHANGES: Removed several obsolete parameters of `write_ods()`

* `overwrite`: always TRUE
* `verbose`: always FALSE

## BREAKING CHANGES: Limited size of sheets writable with `write_ods()`

* Will now refuse to write sheets with size greater than 16384 x 1048576 (max sheet dimensions for Excel and LibreOffice Calc)

## BREAKING CHANGES: read_ods now outputs as tibble by default
* Added `as_tibble` and `.name_repair` as arguments. If `as_tibble` is true, outputs as a tibble using `tibble::as_tibble()` passing on `.name_repair` (default being `"unique"`). **By default** `as_tibble` is set to TRUE.
* Removed `check_names` argument. All name repairs are now dealt with using `vctrs::vec_as_names()`. This will **significantly change** the default names given to outputs. (Names in the style of `check_names = TRUE` can be obtained by setting `.name_repair = minimal`, although this is not advised)

## Defer the removal of `ods_sheets` to v3

There are many reverse dependencies using `ods_sheets`.

# readODS 1.9.0

* Added a `NEWS.md` file to track changes to the package.
* Rewrote all reading functions in C++ for significant speed increase

## BREAKING CHANGES: Removed read.ods and ods_sheets

These have been deprecated for several years. 

## list_ods_sheets

* Added `include_external_data` as an argument (`FALSE` by default). This hides stored data from external sources not normally accessible to the user.

## read_ods

* Changed behaviour when only one row is read. The row now correctly appears as the top row in the dataframe, and a warning is given if column headers are requested that this would cause the output to be empty (**Note:** in this case column names are not assigned)
* Changed behaviour when only one column is read. Previously gave an error. If row names are requested, gives a warning that this would cause the output to be empty, and does not assign names.
* Sheets are now accepted as part of the `range` argument, e.g. `Range = "Sheet2!A2:B7"`. If this and the `sheets` argument are given, this is preferred.
* Merged cells now have their value places in the top-left cell. All other cells that would be covered by the merge are filled with `NA`.
* Added `as_tibble` and `.name_repair` as arguments. If `as_tibble` is true, outputs as a tibble using `tibble::as_tibble()` passing on `.name_repair` (default being `"check_unique"`).

## read_fods

* Reading (but not writing) flat ODS files is now supported using the functions `read_fods()`, `list_fods_sheets()`, `get_num_sheets_in_fods()`. These work the same way as their analogue ODS functions. The extension does not need to be `fods`, however they do need to conform to the OO specification.

## write_ods

* Attempted to fix writing non UTF-8 strings to files. This still has some issues in versions of R \< 4.2, however it should now correctly write most text within your current locale. See [readme](README.md) for more details.
