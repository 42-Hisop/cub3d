#ifndef SPLIT_H
# define SPLIT_H

int		ft_strlen(char const *s);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strstr(char *rd, char c);
char	*check_m(char *rd, int rd_i, char *backup, char c);
char	**ft_split(char *rd, char c);
char	*save(char *rd, char *buf);
char	**split_line(int fd);

#endif
