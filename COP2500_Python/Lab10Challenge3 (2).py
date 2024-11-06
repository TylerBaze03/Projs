<<<<<<< HEAD
# Tyler Bazemore
# Assignment 4.1
# COP2500 ov64
import csv
from csv import writer
csv_filename = 'Lab10.csv'
csv_all = 'combinedcsv.csv'
course_headings = ["course_name", "course_code", "credit_hours", "teacher", "grade"]

with open(csv_all, 'w', newline='') as outcsv:
    writer = csv.writer(outcsv)
    writer.writerow(course_headings)
with open(csv_filename, 'r') as function:
    lab10 = function.read()
with open(csv_all, 'a') as appender:
    appender.write('\n')
    appender.write(lab10)
with open(csv_all) as f:
    reader = csv.DictReader(f)
    for row in reader:
        print(row)


=======
# Tyler Bazemore
# Assignment 4.1
# COP2500 ov64
import csv
from csv import writer
csv_filename = 'Lab10.csv'
csv_all = 'combinedcsv.csv'
course_headings = ["course_name", "course_code", "credit_hours", "teacher", "grade"]

with open(csv_all, 'w', newline='') as outcsv:
    writer = csv.writer(outcsv)
    writer.writerow(course_headings)
with open(csv_filename, 'r') as function:
    lab10 = function.read()
with open(csv_all, 'a') as appender:
    appender.write('\n')
    appender.write(lab10)
with open(csv_all) as f:
    reader = csv.DictReader(f)
    for row in reader:
        print(row)


>>>>>>> b756d6d (Updating repositroy using git)
