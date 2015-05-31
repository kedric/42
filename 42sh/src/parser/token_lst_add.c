/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 16:49:09 by mcassagn          #+#    #+#             */
/*   Updated: 2014/03/27 17:56:40 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static char		*concat_str(char *s1, char *s2)
{
	char		*new_str;
	char		*tmp;

	if (s1 && s2)
	{
		new_str = ft_strjoin(s1, " ");
		tmp = new_str;
		new_str = ft_strjoin(new_str, s2);
		ft_strdel(&tmp);
		return (new_str);
	}
	return (NULL);
}

t_token			*token_lst_add(t_token *new_token, t_token *token_list)
{
	t_token		*curr;
	char		*tmp;

	if (!token_list)
		return (new_token);
	if (!new_token)
		return (token_list);
	curr = token_list;
	while (curr->next)
		curr = curr->next;
	if (curr->type == word && new_token->type == word && (tmp = curr->str))
	{
		curr->str = concat_str(curr->str, new_token->str);
		token_free(&new_token);
		ft_strdel(&tmp);
	}
	else
	{
		curr->next = new_token;
		new_token->prev = curr;
		if (curr->type != pipes && is_redir_operator(curr->str) != unknown
				&& new_token->type == word)
			new_token->type = redir_dest;
	}
	return (token_list);
}

t_token			*token_add(char *str, t_sym type, t_token *token_list)
{
	t_token		*curr;
	t_token		*new;

	if (!(new = create_token()))
		return (NULL);
	new->str = ft_strdup(str);
	new->type = type;
	if (!token_list)
		return (new);
	curr = token_list;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	new->prev = curr;
	return (token_list);
}
