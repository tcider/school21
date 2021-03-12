# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcider <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 11:50:39 by tcider            #+#    #+#              #
#    Updated: 2021/03/10 21:54:50 by tcider           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

RUN apk update && \
	apk upgrade && \
	apk	add mysql gettext && \
	rm -rf /var/cache/apk/*

WORKDIR	/tmp

COPY my.cnf.tmp .
COPY mysql_start.sh .
COPY mysql.sql.tmp .

VOLUME ["/var/lib/mysql"]

EXPOSE 3306

CMD sh mysql_start.sh
