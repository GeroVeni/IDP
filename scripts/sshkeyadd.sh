#!/bin/bash
eval $(ssh-agent)
ssh-add "$HOME/.ssh/engdpt"
