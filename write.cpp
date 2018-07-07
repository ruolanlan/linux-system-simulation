void write(){
	/*功能: 向文件中写入字符(write file1)*/
	int i, inum, length;
	if (argc != 2){
		printf("Command write must have one args. \n");
		return;
	}
	open(3, argv[1]);
	for (i = 0; i < FILENUM; i++)
		if ((file_array[i].inum>0) &&
			!strcmp(file_array[i].file_name, argv[1])) break;
	inum = file_array[i].inum;
	//printf("The length of %s:%d\n", inode_array[inum].file_name, inode_array[inum].length);
	if (inode_array[inum].length == 0){
		inode_array[inum].length = 1024;
		inode_array[inum].address[0] = get_blknum();    //一次分配只有512B的空间，所以调用2次get_blknum()获取1024B空间
		inode_array[inum].address[1] = get_blknum();
		save_inode(inum);
		printf("Input the data(Enter to end):\n");
		gets(temp);
		write_blk(inum);
	}
	else
		printf("This file has content,it can't be written.\n");
	close(argv[1]);
}
