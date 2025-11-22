def filter_comment_lines(src_file, dest_file):
 """
 This function accepts the names of source file and destination file as parameters,
 reads the source file line by line and writes only non comment lines from it
 (lines that donot start with #) to the destination file.
 """
 with open(src_file, "r") as infile, open(dest_file, "w") as outfile:
  for line in infile:
   if not line.startswith('#'):
     outfile.write(line)
 print("Filtering of comment lines succesful, check the contents of destination file")
src=input("Enter the name of the source file:")
dest=input("Enter the name of the destination file:")
filter_comment_lines(src,dest)
