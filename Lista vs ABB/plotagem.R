library("ggplot2")

Lista = read.csv("Lista.csv")
ABB = read.csv("ABB.csv")

plot1 <- ggplot(data = Lista, aes(x = valores,y = comparacoes)) +geom_point(color='red') +xlab("valor")+ ylab("comparacoes")+ggtitle("Grafico Lista") +stat_function(fun=function(x)x, geom="line", color="black")
plot2 <- ggplot(data = ABB, aes(x = valores,y = comparacoes)) +geom_point(color='red') +xlab("valor")+ ylab("comparacoes")+ggtitle("Grafico ABB") +stat_function(fun=function(x)log2(x), geom="line", color="black")

multiplot <- function(..., plotlist=NULL, file, cols=1, layout=NULL) {
  library(grid)
  plots <- c(list(...), plotlist)
  numPlots = length(plots)
  if (is.null(layout)) {
    layout <- matrix(seq(1, cols * ceiling(numPlots/cols)),
                     ncol = cols, nrow = ceiling(numPlots/cols))
  }
  
  if (numPlots==1) {
    print(plots[[1]])
    
  } else {
    grid.newpage()
    pushViewport(viewport(layout = grid.layout(nrow(layout), ncol(layout))))
    for (i in 1:numPlots) {
      matchidx <- as.data.frame(which(layout == i, arr.ind = TRUE))
      print(plots[[i]], vp = viewport(layout.pos.row = matchidx$row,
                                      layout.pos.col = matchidx$col))
    }
  }
}

multiplot(plot1,plot2)
