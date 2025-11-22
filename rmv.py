def rmv_cmm(src_file,dest_file):
    with open(src_file,"r")as infile, open(dest_file,"w")as outfile:
        for line in infile:
            if not line.startswith('#'):
                outfile.write(line)
    print("copy successful")
srcfile=input("enter the source file")
destfile=input("enter the destination file")
rmv_cmm(srcfile,destfile)
