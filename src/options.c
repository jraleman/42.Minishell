
#import "minishell.h"

static void	parse_options(t_sh *sh, char *opt[])
{
	int		i;

	i = 0;
	while (opt[i])
	{
		sh->opt.prompt = (!(strcmp(opt[i], "varela") ? PRMPT_BNS : PRMPT_DFL);
		// ...
	}
	return ;
}

t_sh		*sh_init(char *opt[])
{
	t_sh	*sh

	sh = (t_sh *)malloc(sizeof(t_sh));
	if (sh)
	{
		parse_options(&sh, opt);
		// ...
	}
	return (sh);
}
