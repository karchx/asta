module Tokenizer where

import Data.Char (isDigit, isSpace)

data Token = Number Double
           | END
           | PLUS
           | MINUS
           | MULTIPLY
           | DIVIDE
           | UNKNOWN Char
           deriving (Show, Eq)


tokenize :: String -> [Token]
tokenize [] = []
tokenize (x:xs)
    | isDigit x || x == '.' = tokenizeNumber (x:xs)
    | x == '+' = PLUS : tokenize xs
    | x == '-' = MINUS : tokenize xs
    | x == '*' = MULTIPLY : tokenize xs
    | x == '/' = DIVIDE : tokenize xs
    | isSpace x = tokenize xs
    | otherwise = UNKNOWN x : tokenize xs


tokenizeNumber :: String -> [Token]
tokenizeNumber s =
    let (numStr, rest) = span (\x -> isDigit x || x == '.') s
    in Number (read numStr) : tokenize rest
