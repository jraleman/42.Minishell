void ft_error(char *msg, int err, char *exe)
{
	printf("%s: %s\n", exe, msg);
	exit(err);
}
