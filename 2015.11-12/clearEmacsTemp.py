import os
import os.path
import re

emacstemp = re.compile(r'^.+?\..+?~$')

def getlevel( level):
	return '--|'*(level-1)

def removeEmacsTempFile( targetDir, level ):
	if not os.path.exists( targetDir ):
		return
	for file in os.listdir( targetDir ):
		targetFile = os.path.join( targetDir, file )
		print(getlevel(level),targetDir)
		if os.path.isdir( targetFile ):
			removeEmacsTempFile( targetFile, level +1 )
		elif emacstemp.match(file) and os.path.isfile(targetFile):
			print(getlevel(level+1),file)
			os.remove(targetFile)

removeEmacsTempFile(os.path.abspath('.'), 1)
