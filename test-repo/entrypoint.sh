#!/bin/bash
until docker inspect -f '{{.State.Status}}' app | grep -q "exited"; do
    sleep 1
done

echo "<pre>" > /usr/share/nginx/html/index.html
docker logs app >> /usr/share/nginx/html/index.html 2>&1
echo "</pre>" >> /usr/share/nginx/html/index.html

exec nginx -g "daemon off;"