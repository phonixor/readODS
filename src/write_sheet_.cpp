#include "cpp11.hpp"
#include "cpp11/r_string.hpp"
#include "cpp11/list.hpp"
#include <R.h>
#include <Rinternals.h>
#include <fstream>
#include <iostream>

void cell_out_ (const cpp11::r_string& value_type, const cpp11::r_string& value, std::ofstream& xml_file) {
    const char* value_type_c = Rf_translateCharUTF8(value_type);
    const char* value_c = Rf_translateCharUTF8(value);
    xml_file << "<table:table-cell office:value-type=\"";
    xml_file << value_type_c;
    if (strcmp(value_type_c, "string") != 0) {
	xml_file << "\" office:value=\"";
	xml_file << value_c;
    }
    xml_file << "\" table:style-name=\"ce1\"><text:p>";
    xml_file << value_c;
    xml_file << "</text:p></table:table-cell>";
}

void pad_rows_ (const bool& padding, const int& cols, const int& cmax, std::ofstream& xml_file) {
    if (cols < cmax && padding) {
	xml_file << "<table:table-cell table:number-columns-repeated=\"";
	xml_file << cmax - cols;
	xml_file << "\"/>";
    }    
}

[[cpp11::register]]
cpp11::r_string write_sheet_(const std::string& filename,
			     const cpp11::list_of<cpp11::strings>& x_list,
			     const cpp11::strings& column_types,
			     const std::string& sheet,
			     const int cmax,
			     const bool row_names,
			     const bool col_names,
			     const cpp11::strings& rownames_x,
			     const cpp11::strings& colnames_x,
			     const bool na_as_string,
			     const bool padding,
			     const std::string& header,
			     const std::string& footer) {
    int rows, cols;
    if (col_names) {
	rows = x_list[0].size() + 1;
    } else {
	rows = x_list[0].size();
    }
    if (row_names) {
	cols = column_types.size() + 1;
    } else {
	cols = column_types.size();
    }    
    // please escape all strings first!
    std::ofstream xml_file(filename);
    // gen_sheet_tag
    xml_file << header;
    xml_file << "<table:table table:name=\"";
    xml_file << sheet;
    xml_file << "\" table:style-name=\"ta1\"><table:table-column table:style-name=\"co1\" table:number-columns-repeated=\"";
    
    if (padding) {
	xml_file << cmax;
    } else {
	xml_file << cols;
    }
    xml_file << "\" table:default-cell-style-name=\"ce1\"/>";
    // add_data	
    if (col_names) {
	xml_file << "<table:table-row table:style-name=\"ro1\">";
	if (row_names) {
	    cell_out_("string", "", xml_file);
	}
	for (int j = 0; j < colnames_x.size(); j++) {
	    cell_out_("string", colnames_x[j], xml_file);
	}
	pad_rows_(padding, cols, cmax, xml_file);
	xml_file << "</table:table-row>";
    }
    for (int i = 0; i < x_list[0].size(); i++) {
	xml_file << "<table:table-row table:style-name=\"ro1\">";
	if (row_names) {
	    cell_out_("string", rownames_x[i], xml_file);
	}
	for (int j = 0; j < column_types.size(); j++) {
	    //TODO: NA
	    cell_out_(column_types[j], x_list[j][i], xml_file);
	}
	pad_rows_(padding, cols, cmax, xml_file);
	xml_file << "</table:table-row>";
    }
    // pad_columns
    if (rows < 1048576 && padding) {
	xml_file << "<table:table-row table:style-name=\"ro1\" table:number-rows-repeated=\"";
	xml_file << 1048576 - rows;
	xml_file << "\"><table:table-cell table:number-columns-repeated=\"";
	xml_file << cmax;
	xml_file << "\"/></table:table-row>";
    }
    xml_file << "</table:table>";
    xml_file << footer;
    xml_file.close();
    return filename;	
}