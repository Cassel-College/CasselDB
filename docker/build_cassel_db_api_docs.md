
# Build CasselDB API Docs

```shell
docker run --name CasselDB_API_Doc -p 9095:80 -v /home/Code/CasselDB/doc/html:/usr/share/nginx/html:ro -d nginx
```