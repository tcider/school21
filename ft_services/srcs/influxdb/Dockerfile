# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcider <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 11:50:39 by tcider            #+#    #+#              #
#    Updated: 2021/03/12 12:07:36 by tcider           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

RUN apk update && \
	apk upgrade && \
	apk	add influxdb && \
	rm -rf /var/cache/apk/*

VOLUME ["/root/.influxdb"]

EXPOSE 8086

ENTRYPOINT ["/usr/sbin/influxd"]
