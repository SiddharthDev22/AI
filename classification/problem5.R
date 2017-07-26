library("MASS")
source("util.R")

main <- function() {

	trainingSetMat = matrix(data = as.matrix( read.table("dataset/problem3.dat") ), nrow = 5, ncol = 300, byrow = TRUE)
	labelSetMat <- matrix(data = as.matrix( read.table("dataset/problem4.dat") ), nrow = 1, ncol = 300)
	testSetMat <- matrix(data = as.matrix( read.table("dataset/problem5.dat") ), nrow = 5, ncol = 5, byrow = TRUE)

	trainingSetFrame <- as.data.frame(t(trainingSetMat))
	
	qdaModel = qda(trainingSetFrame, grouping = labelSetMat)
	
	for(i in 1 : nrow(testSetMat)) {
		class = predict(qdaModel, testSetMat[ ,i])$class
		cat(paste("test", i, "in", class, "\n"))
	}
}
main()