Data <- read.table("arquivo.csv", header = FALSE)
plot(Data[,1],Data[,1], xlab = "Valores", ylab = "Comparacoes", type = "n", lwd = 4, col = "white")
legend("topleft", legend=c("Lista", "ABB"),lty=c(1,1), col=c("blue","red"), lwd=2:2, bty="n", pch=c(NA,NA))
points(Data[,2], lwd = 0, col = "blue")
points(Data[,3], lwd = 0, col = "red")

title(main = "Lista VS ABB")