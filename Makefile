fresh: clean all

.phony all:
all:  amdb.txt   dfac.dat
	#$(eval amdbdiff = $(shell diff amdb.dat.old amdb.dat  2>&1 > amdb.dat.diff; echo $$?))
	#$(eval dfacdiff = $(shell diff dfac.dat dfac.dat.old  2>&1 > /dev/null; echo $$?))
	#@([ ${amdbdiff} -eq 0 ] && [ ${dfacdiff} -eq 0 ] && echo no changes) || (echo some changes; make upload)
	#@([ ${amdbdiff} -eq 0 ] && echo no changes) || (echo some changes; make upload)

amdb.txt: amdb.dat
	date -u "+Last Updated %a, %b %d, %Y at %H%M UTC" > update.txt
	cat update.txt > amdb.txt
	echo "FAC_ID|FREQ|CALL|STATE|COL|PWR_D|PWR_N|PWR_C|LAT|LON|STATUS|CALL_HIST" >> amdb.txt
	cat amdb.dat >> amdb.txt


amdb.dat:  amdb auths.dat fachist.dat
	./amdb > amdb.dat

################################
# Compile the programs we need
fac: fac.c parse.c amdb.h
	gcc -o fac fac.c parse.c

ant: ant.c parse.c amdb.h
	gcc -o ant ant.c parse.c

licfilver: licfilver.c parse.c amdb.h
	gcc -o licfilver licfilver.c parse.c

auths: auths.c parse.c amdb.h
	gcc -o auths auths.c parse.c -g

amdb: amdb.c parse.c amdb.h
	gcc -o amdb amdb.c parse.c

appfac: appfac.c parse.c amdb.h
	gcc -o appfac appfac.c parse.c

dfac:   dfac.c  amdb.h
	gcc -o dfac dfac.c parse.c


#################################
#  Get the zip files from the FCC

license_filing_version.zip:
	$(eval currdate = $(shell date "+%m-%d-%Y"))
	wget https://enterpriseefiling.fcc.gov/dataentry/api/download/dbfile/$(currdate)/license_filing_version.zip

facility.zip:
	$(eval currdate = $(shell date "+%m-%d-%Y"))
	wget https://enterpriseefiling.fcc.gov/dataentry/api/download/dbfile/$(currdate)/facility.zip

app_am_antenna.zip:
	$(eval currdate = $(shell date "+%m-%d-%Y"))
	wget https://enterpriseefiling.fcc.gov/dataentry/api/download/dbfile/$(currdate)/app_am_antenna.zip

application_facility.zip:
	$(eval currdate = $(shell date "+%m-%d-%Y"))
	wget https://enterpriseefiling.fcc.gov/dataentry/api/download/dbfile/$(currdate)/application_facility.zip

application.zip:
	$(eval currdate = $(shell date "+%m-%d-%Y"))
	wget https://enterpriseefiling.fcc.gov/dataentry/api/download/dbfile/$(currdate)/application.zip

facility_history.zip:
	$(eval currdate = $(shell date "+%m-%d-%Y"))
	wget https://enterpriseefiling.fcc.gov/dataentry/api/download/dbfile/$(currdate)/facility_history.zip



##########################
# Extract the ZIP files

facility.dat: facility.zip
	unzip facility.zip

app_am_antenna.dat: app_am_antenna.zip
	unzip app_am_antenna.zip

license_filing_version.dat: license_filing_version.zip
	unzip license_filing_version.zip

application_facility.dat: application_facility.zip
	unzip application_facility.zip

application.dat: application.zip
	unzip application.zip

facility_history.dat: facility_history.zip
	unzip facility_history.zip


##########################
# Distill the FCC data 

auths.dat: auths appfac.dat ant.dat fac.dat licfilver.dat
	./auths |sort  -k1,1n -k2,2 -t "|" > auths.dat

ant.dat: ant app_am_antenna.dat
	./ant > ant.dat

fac.dat: fac facility.dat 
	./fac | sort -k6,6  -t "|" > fac.dat

appfac.dat: appfac application_facility.dat
	./appfac | sort  -k2,2n -t "|" > appfac.dat

licfilver.dat: licfilver license_filing_version.dat 
	./licfilver | sort -k1,1 -t "|" > licfilver.dat

dfac.dat: dfac facility.dat
	./dfac > dfac.dat

fachist.dat: facility_history.dat
	sort -t '|' -k9,9 -k8,8n facility_history.dat > fachist.dat


############
# cleanup
clean:
	mv amdb.dat amdb.dat.old
	mv dfac.dat dfac.dat.old
	rm -f *.dat *.zip *.txt

pristine: clean
	rm -f fac dfac  ant auths appfac licfilver amdb


upload: 
	scp amdb.dat dfac.dat update.txt rebuild gentoo@gentoo.net:~/mivadata/amdb/
	scp amdb.txt gentoo@gentoo.net:~/radio/amdb/
