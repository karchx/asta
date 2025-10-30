module Main where

import Tokenize


removeNewLine :: String -> String
removeNewLine = filter (\c -> c /= '\n')

main :: IO()
main = do
    putStrLn "Enter an expression (e.g, 5 + 5 - 2): "
    input <- getLine


    putStrLn ("Result: " ++ removeNewLine input)
