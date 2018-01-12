set -e

mkdir -p build/docker/
cp doc/cbcd-example.cfg build/clang.debug/cbcd build/docker/
cp Builds/Docker/Dockerfile-testnet build/docker/Dockerfile
mv build/docker/cbcd-example.cfg build/docker/cbcd.cfg
strip build/docker/cbcd
docker build -t cbc/cbcd:$CIRCLE_SHA1 build/docker/
docker tag cbc/cbcd:$CIRCLE_SHA1 cbc/cbcd:latest

if [ -z "$CIRCLE_PR_NUMBER" ]; then
  docker tag cbc/cbcd:$CIRCLE_SHA1 cbc/cbcd:$CIRCLE_BRANCH
fi
