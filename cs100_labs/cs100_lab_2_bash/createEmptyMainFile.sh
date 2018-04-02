#!/bin/sh

cat _.txt >> main.cc

cat <<EOF >>main.cc
int main(int argc, const char** argv)
{ }
EOF
