library(ggplot2)


args = commandArgs(trailingOnly=TRUE)
if (length(args) == 0 || length(args) == 1) {
  stop("Please specify the right number of parameters.", call.=FALSE)
} else if (length(args) == 2) {
  args[3] = "RGrapher_out.pdf"
}

pdf(args[3])
csv_df<-read.csv(args[2], header=TRUE, sep=";")
ggplot(data=csv_df, aes(x=face_no, y=normalized_sum)) +
  ylim(0, 1) +
  ggtitle(args[1]) +
  xlab("Face number") +
  ylab("Normalized index derived from the sum of scalar products") +
  theme(plot.title = element_text(size=14, face="bold", hjust=0.5)) +
  geom_bar(stat="identity")
