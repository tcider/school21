# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    setup.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcider <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/25 13:27:22 by tcider            #+#    #+#              #
#    Updated: 2021/03/12 12:24:21 by tcider           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Minikube, Virtualbox, Docker and Kubectl should be pre-installed
# brew cask install docker
# brew install virtualbox
# brew install minikube

minikube stop
#minikube delete
#rm ~/.ssh/known_hosts
minikube start --driver=virtualbox --cpus 4

# Exporting env
eval $(minikube docker-env)

# Enabling addons
minikube addons enable metrics-server
#minikube addons enable dashboard

# Global ConfigMap 
kubectl apply -f ./srcs/yaml/config.yaml

# MetalLB as LoadBalancer service
# Enabling StrictARP mode in kube-proxy for MetalLB
kubectl get configmap kube-proxy -n kube-system -o yaml | \
	sed -e "s/strictARP: false/strictARP: true/" | \
	kubectl apply -f - -n kube-system
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist \
	--from-literal=secretkey="$(openssl rand -base64 128)"
kubectl apply -f ./srcs/yaml/metallb.yaml

# Nginx
docker build -t nginx-image ./srcs/nginx/
kubectl apply -f ./srcs/yaml/nginx.yaml

# MySQL
docker build -t mysql-image ./srcs/mysql/
kubectl apply -f ./srcs/yaml/mysql.yaml

# PhpMyAdmin
docker build -t phpmyadmin-image ./srcs/phpmyadmin/
kubectl apply -f ./srcs/yaml/phpmyadmin.yaml

# Wordpress
docker build -t wordpress-image ./srcs/wordpress/
kubectl apply -f ./srcs/yaml/wordpress.yaml

# FTPS
docker build -t ftps-image ./srcs/ftps/
kubectl apply -f ./srcs/yaml/ftps.yaml

# InfluxDB
docker build -t influxdb-image ./srcs/influxdb/
kubectl apply -f ./srcs/yaml/influxdb.yaml

# Telegraf
docker build -t telegraf-image ./srcs/telegraf/
kubectl apply -f ./srcs/yaml/telegraf.yaml

# Grafana
docker build -t grafana-image ./srcs/grafana/
kubectl apply -f ./srcs/yaml/grafana.yaml

# Dashboard
minikube dashboard &> /dev/null &
