#include "sqlite\sqlite3.h"

#include <stdio.h>
#include <iostream>

int main() {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	char * sql;

	rc=sqlite3_open("compensatii.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}

	sql = "CREATE TABLE CLUJ("
		"ID INT PRIMARY        KEY      NOT NULL,"
		"CAUZA            TEXT      NOT NULL,"
		"NR_COMPENSATII_ACORDATE_JT          INT     NOT NULL,"
		"NR_COMPENSATII_ACORDATE_MT          INT     NOT NULL,"
		"NR_COMPENSATII_ACORDATE_IT          INT     NOT NULL,"
		"VALOARE_COMPENSATII_ACORDATE_JT          INT     NOT NULL,"
		"VALOARE_COMPENSATII_ACORDATE_MT          INT     NOT NULL,"
		"VALOARE_COMPENSATII_ACORDATE_IT          INT     NOT NULL,"
		"PERSOANA_JURIDICA          VCHAR(2)     NOT NULL,"
		"PERSOANA_FIZICA          VCHAR(2)     NOT NULL,"
		"OBS          INT     NOT NULL,"
		"SAPTAMANA            INT      NOT NULL);";
	sql = "CREATE TABLE ORADEA("
		"ID INT PRIMARY        KEY      NOT NULL,"
		"CAUZA            TEXT      NOT NULL,"
		"NR_COMPENSATII_ACORDATE_JT          INT     NOT NULL,"
		"NR_COMPENSATII_ACORDATE_MT          INT     NOT NULL,"
		"NR_COMPENSATII_ACORDATE_IT          INT     NOT NULL,"
		"VALOARE_COMPENSATII_ACORDATE_JT          INT     NOT NULL,"
		"VALOARE_COMPENSATII_ACORDATE_MT          INT     NOT NULL,"
		"VALOARE_COMPENSATII_ACORDATE_IT          INT     NOT NULL,"
		"PERSOANA_JURIDICA          VCHAR(2)     NOT NULL,"
		"PERSOANA_FIZICA          VCHAR(2)     NOT NULL,"
		"OBS          INT     NOT NULL,"
		"SAPTAMANA            INT      NOT NULL);";
	sql = "CREATE TABLE BAIAMARE("
		"ID INT PRIMARY        KEY      NOT NULL,"
		"CAUZA            TEXT      NOT NULL,"
		"NR_COMPENSATII_ACORDATE_JT          INT     NOT NULL,"
		"NR_COMPENSATII_ACORDATE_MT          INT     NOT NULL,"
		"NR_COMPENSATII_ACORDATE_IT          INT     NOT NULL,"
		"VALOARE_COMPENSATII_ACORDATE_JT          INT     NOT NULL,"
		"VALOARE_COMPENSATII_ACORDATE_MT          INT     NOT NULL,"
		"VALOARE_COMPENSATII_ACORDATE_IT          INT     NOT NULL,"
		"PERSOANA_JURIDICA          VCHAR(2)     NOT NULL,"
		"PERSOANA_FIZICA          VCHAR(2)     NOT NULL,"
		"OBS          INT     NOT NULL,"
		"SAPTAMANA            INT      NOT NULL);";
	sql = "CREATE TABLE SATUMARE("
		"ID INT PRIMARY        KEY      NOT NULL,"
		"CAUZA            TEXT      NOT NULL,"
		"NR_COMPENSATII_ACORDATE_JT          INT     NOT NULL,"
		"NR_COMPENSATII_ACORDATE_MT          INT     NOT NULL,"
		"NR_COMPENSATII_ACORDATE_IT          INT     NOT NULL,"
		"VALOARE_COMPENSATII_ACORDATE_JT          INT     NOT NULL,"
		"VALOARE_COMPENSATII_ACORDATE_MT          INT     NOT NULL,"
		"VALOARE_COMPENSATII_ACORDATE_IT          INT     NOT NULL,"
		"PERSOANA_JURIDICA          VCHAR(2)     NOT NULL,"
		"PERSOANA_FIZICA          VCHAR(2)     NOT NULL,"
		"OBS          INT     NOT NULL,"
		"SAPTAMANA            INT      NOT NULL);";
	sql = "CREATE TABLE BISTRITA("
		"ID INT PRIMARY        KEY      NOT NULL,"
		"CAUZA            TEXT      NOT NULL,"
		"NR_COMPENSATII_ACORDATE_JT          INT     NOT NULL,"
		"NR_COMPENSATII_ACORDATE_MT          INT     NOT NULL,"
		"NR_COMPENSATII_ACORDATE_IT          INT     NOT NULL,"
		"VALOARE_COMPENSATII_ACORDATE_JT          INT     NOT NULL,"
		"VALOARE_COMPENSATII_ACORDATE_MT          INT     NOT NULL,"
		"VALOARE_COMPENSATII_ACORDATE_IT          INT     NOT NULL,"
		"PERSOANA_JURIDICA          VCHAR(2)     NOT NULL,"
		"PERSOANA_FIZICA          VCHAR(2)     NOT NULL,"
		"OBS          INT     NOT NULL,"
		"SAPTAMANA            INT      NOT NULL);";
	sql = "CREATE TABLE ZALAU("
		"ID INT PRIMARY        KEY      NOT NULL,"
		"CAUZA            TEXT      NOT NULL,"
		"NR_COMPENSATII_ACORDATE_JT          INT     NOT NULL,"
		"NR_COMPENSATII_ACORDATE_MT          INT     NOT NULL,"
		"NR_COMPENSATII_ACORDATE_IT          INT     NOT NULL,"
		"VALOARE_COMPENSATII_ACORDATE_JT          INT     NOT NULL,"
		"VALOARE_COMPENSATII_ACORDATE_MT          INT     NOT NULL,"
		"VALOARE_COMPENSATII_ACORDATE_IT          INT     NOT NULL,"
		"PERSOANA_JURIDICA          VCHAR(2)     NOT NULL,"
		"PERSOANA_FIZICA          VCHAR(2)     NOT NULL,"
		"OBS          INT     NOT NULL,"
		"SAPTAMANA            INT      NOT NULL);";
	rc = sqlite3_exec(db, sql, NULL, NULL, NULL);



	sqlite3_close(db);
	return 0;
}