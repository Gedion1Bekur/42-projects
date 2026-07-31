#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get the size of the cotainter  and that size need to word witht out containter
// get  the container size by counting words with out delimiter
// then once i get this one asign to malloc + 1 as 2D ptr bucket
// then we neeed to word counter agoan to only find the words ten assign them to mallox
// we need to create a fun that  will checck when we delegtting malloc to ptr index n
// it it fails free teh the main containter , if not go
// var i need  how many var do

/// in case of one malloc fail we need fun freeer fun

static int	safe_malloc(char **token_v, int pos, size_t buf)
{
	int	i;

	i = 0;
	token_v[pos] = malloc(buf);
	if (NULL == token_v[pos])
	{
		while (i < pos)
		{
			free(token_v[i++]);
		}
		free(token_v);
		return (1);
	}
	return (0);
}
static int	fill_tokens(char **token_v, char const *s, char del)
{
	size_t		len_token;
	int			pos;
	char const	*token_start;

	pos = 0;
	while (*s)
	{
		while (*s == del && *s)
			s++;
		if (*s == '\0')
			break ;
		token_start = s;
		len_token = 0;
		while (*s != del && *s)
		{
			len_token++;
			s++;
		}
		if (safe_malloc(token_v, pos, len_token + 1))
			return (1);
		strlcpy(token_v[pos], token_start, len_token + 1);
		pos++;
	}
	return (0);
}
static int	count_tokens(char const *s, char del)
{
	size_t	tokens;
	int		inside_token;

	tokens = 0;
	inside_token = 0;
	while (*s)
	{
		if (*s != del && !inside_token)
		{
			inside_token = 1;
			tokens++;
		}
		else if (*s == del)
		{
			inside_token = 0;
		}
		s++;
	}
	return (tokens);
}

char	**ft_split(char const *s, char c)
{
	size_t	tokens;
	char	**tokens_v;

	if (!s)
		return (NULL);
	tokens = 0;
	tokens = count_tokens(s, c);
	tokens_v = malloc((tokens + 1) * sizeof(char *));
	if (!tokens_v)
		return (NULL);
	tokens_v[tokens] = NULL;
	if (fill_tokens(tokens_v, s, c))
		return (NULL);
	return (tokens_v);
}
