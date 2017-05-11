source("util.R")

main <- function() {
	
	dataSetMatrix <- as.matrix( read.table("dataset/problem1.dat") )

	cat(paste("Mean          M: ", m.Mean(dataSetMatrix),"\n"))
	cat(paste("Mean          R: ", mean(dataSetMatrix),"\n"))
	cat(paste("----------------------------------\n"))
	cat(paste("variance      M:", m.Variance(dataSetMatrix),"\n"))
	cat(paste("variance      R:", var(dataSetMatrix),"\n"))
	cat(paste("----------------------------------\n"))
	cat(paste("std deviation M:", m.StdDeviation(dataSetMatrix),"\n"))
	cat(paste("std deviation R:", sd(dataSetMatrix),"\n"))
}

main()