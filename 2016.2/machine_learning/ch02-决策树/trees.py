from math import log
import operator

def calcShannonEnt(dataSet): 		# Calculate the shannonEnt
	numEntries = len(dataSet)
	labelCounts = {}
	for featVec in dataSet:
		currentLabel = featVec[-1]
		if currentLabel not in labelCounts.keys():
			labelCounts[currentLabel] = 0
		labelCounts[currentLabel] += 1
	shannonEnt = 0.0
	for key in labelCounts:
		prob = float(labelCounts[key])/numEntries
		shannonEnt -= prob * log(prob,2)  # p(x)logp(x)
	return shannonEnt

def createDataSet():		# Only for test
	dataSet = [[1,1,'yes'],
				[1,1,'yes'],
				[1,0,'no'],
				[0,1,'no'],
				[0,1,'no']]
	labels = ['no surfacing','flippers']
	return dataSet,labels

def splitDataSet(dataSet, axis, value):   		# category by a specific feature
	retDataSet = []
	for featVec in dataSet:
		if featVec[axis] == value:
			reducedFeatVec = featVec[:axis]
			reducedFeatVec.extend(featVec[axis+1:])
			retDataSet.append(reducedFeatVec)
	return retDataSet

def chooseBestFeatureToSplit(dataSet):			# choose a best feature to split the dataSet
	numFeatures = len(dataSet[0]) - 1
	baseEntropy = calcShannonEnt(dataSet)
	bestInfoGain = 0.0 ; bestFeature = -1
	for i in range(numFeatures):
		featList = [example[i] for example in dataSet]
		uniqueVals = set(featList)
		newEntropy = 0.0
		for value in uniqueVals:
			subDataSet = splitDataSet(dataSet, i ,value)
			prob = len(subDataSet)/float(len(dataSet))
			newEntropy += prob * calcShannonEnt(subDataSet)		# careful, newEntropy < 0
		infoGain = baseEntropy - newEntropy
		if infoGain > bestInfoGain:
			bestInfoGain = infoGain
			bestFeature = i
	return bestFeature

def majorityCnt(classList): 		# find the most category in the part examples
	classCount = {}
	for vote in classList:
		if vote not in classCount.keys() :
			classCount[vote] = 0
		classCount[vote] += 1
	sortedClassCount = sorted(classCount.iteritems(),\
		key = operator.itemgetter(1), reverse = True)
	return sortedClassCount[0][0]

def createTree(dataSet, labels):			# build decision tree
	classList = [example[-1] for example in dataSet]
	if classList.count(classList[0]) == len(classList):		# all the elements are the same category
		return classList[0]
	if len(dataSet[0]) == 1:			# all the features have been used
		return majorityCnt(classList)
	bestFeat = chooseBestFeatureToSplit(dataSet)
	bestFeatLabel = labels[bestFeat]
	myTree = {bestFeatLabel:{}}
	del(labels[bestFeat])
	featValues = [example[bestFeat] for example in dataSet]
	uniqueVals = set(featValues)
	for value in uniqueVals:
		subLabels = labels[:]				# deep copy
		myTree[bestFeatLabel][value] = createTree(splitDataSet\
			(dataSet, bestFeat, value), subLabels)
	return myTree

def classify(inputTree, featLabels, testVec):				# classify
	firstStr = inputTree.keys()[0]
	secondDict = inputTree[firstStr]
	featIndex = featLabels.index(firstStr)
	for key in secondDict.keys():
		if testVec[featIndex] == key:
			if type(secondDict[key]).__name__ == 'dict':
				classLabel = classify(secondDict[key], featLabels, testVec)
			else:
				classLabel = secondDict[key]
	return classLabel

def storeTree(inputTree, filename):
	import pickle
	with open(filename,'w') as fw:
		pickle.dump(inputTree, fw)

def grabTree(filename):
	import pickle
	fr = open(filename)
	return pickle.load(fr)