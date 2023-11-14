/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:46:16 by aguediri          #+#    #+#             */
/*   Updated: 2023/11/04 18:24:26 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char	*heredoc(const char *delimiter)
// {
// 	char	*buffer;
// 	char	*line;
// 	size_t	bufsize;
// 	size_t	totalSize;
// 	ssize_t	bytesRead;
// 	char	*temp;

// 	buffer = NULL;
// 	line = NULL;
// 	bufsize = 0;
// 	totalSize = 0;
// 	printf("Enter Heredoc content. Terminate with '%s':\n", delimiter);
// 	while (1)
// 	{
// 		bytesRead = getline(&line, &bufsize, stdin);
// 		if (bytesRead == -1)
// 		{
// 			perror("Error reading input");
// 			free(buffer);
// 			free(line);
// 			return (NULL);
// 		}
// 		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
// 		{
// 			free(line);
// 			break ;
// 		}
// //		temp = realloc(buffer, totalSize + bytesRead);
// 		if (temp == NULL)
// 		{
// 			perror("Memory allocation error");
// 			free(buffer);
// 			free(line);
// 			return (NULL);
// 		}
// 		buffer = temp;
// 		//ft_strlcpy(buffer + totalSize, line, ft_strlen(line)+1);
//         buffer = ft_strjoin(buffer, line);
// 		totalSize += bytesRead;
// 	}
// //	free(line);
//     printf("%s",buffer);
// 	return (buffer);
// }
char *heredoc(const char *delimiter) {
    char *buffer = ft_calloc(1,1);
    char *line = NULL;
    size_t bufsize = 0;
    size_t totalSize = 0;
    ssize_t bytesRead;

    printf("Enter Heredoc content. Terminate with '%s':\n", delimiter);
    
    while (1) {
        bytesRead = getline(&line, &bufsize, stdin);

        if (bytesRead == -1) {
            perror("Error reading input");
            free(buffer);
            free(line);
            return NULL;
        }

        if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0) {
            free(line);
            break;
        }

        // Reallocate memory for buffer
        char *temp = realloc(buffer, totalSize + bytesRead + 1);
        if (temp == NULL) {
            perror("Memory allocation error");
            free(buffer);
            free(line);
            return NULL;
        }
        buffer = temp;

        // Use your custom function to join the line to the buffer
        buffer = ft_strjoin(buffer, line);

        totalSize += bytesRead;
    }

    // free(line);
    buffer = ft_strjoin(buffer, delimiter);
    return buffer;
}
// int	main(void)
// {
// 	char *heredoc_content = heredoc("\'");

// 	if (heredoc_content != NULL)
// 	{
// 		printf("Heredoc Content:\n%s", heredoc_content);
// 		free(heredoc_content);
// 	}

// 	return (0);
// }