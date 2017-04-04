size = 1000000
array = []

File.open('file.txt', 'w'){ |file| file.write "" }

puts Time.now
array = (1..size).to_a
symbols_and_numbers = ['a'..'z','A'..'Z','0'..'9'].map{ |range| range.to_a }.flatten
symbols = ['a'..'z','A'..'Z'].map{ |range| range.to_a }.flatten
numbers = ['0'..'9'].map{ |range| range.to_a }.flatten
string = ""

size.times do |i|
	number = array.delete_at(rand(array.size)).to_s
	File.open('file.txt', 'a'){ |file| file.write (0...32).map{ symbols_and_numbers[rand(symbols_and_numbers.size)] }.join + number + (0...(8 - number.size)).map{ symbols[rand(symbols.size)] }.join + "\n" }
end

puts "Файл записан"
puts Time.now
