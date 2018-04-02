#!/bin/sh

read -p 'Please enter your class name: ' classname
hh="_hh"
cat main.cc >> $classname.cc

cat _.txt >> $classname.hh

cat <<EOF >>$classname.cc
#include "./$classname.hh"

$classname::$classname()
{}

$classname::~$classname()
{}
EOF

cat <<EOF >>$classname.hh
#ifndef $classname$hh
#define $classname$hh

class $classname
{
  public:
    $classname();
    ~$classname();

  private:
};
#endif
EOF
