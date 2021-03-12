# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcider <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/25 15:39:50 by tcider            #+#    #+#              #
#    Updated: 2021/03/12 11:09:02 by tcider           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

RUN apk update && \
	apk upgrade && \
	apk add vsftpd openssl gettext &&  \
	rm -rf /var/cache/apk/*

WORKDIR	/tmp

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-out /etc/ssl/vsftpd.crt \
	-keyout /etc/ssl/vsftpd.key \
	-subj "/C=RU/ST=Tatarstan/L=Kazan/O=School21/CN=localhost"

COPY vsftpd.conf.tmp .
COPY ftps_start.sh .

VOLUME ["/ftps"]

EXPOSE 21 20 21000

CMD sh ftps_start.sh
