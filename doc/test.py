import camelot
tables = camelot.read_pdf('ARINC424.pdf', pages="42-124")
print(tables.n)
tables.export('ARINC424.json', f='json')
tables.export('ARINC424.csv', f='csv')