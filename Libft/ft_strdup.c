#include <libft.h>

static size_t calculate_lenght(char *s1)
{
	size_t len;

	len = 0;
	while (s1[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char s1)
{
	size_t	len;
	char	*new;
	int		i;
	
	//calcular longitud
	len = calculate_lenght(s1);

	//reservar espacio de memoria
	new = malloc(sizeof(char) * (len));

	//copiar string
	i = 0;
	while(s1[i] != '\0')
	{
		new[i] = s1[i]
		i++;
	}
	new[i] = '\0';
	return (new);

}
