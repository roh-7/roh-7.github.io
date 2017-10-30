set ns [new Simulator]

set n0 [$ns node]
set n1 [$ns node]

$ns at 0.0 "$n0 label Sender"
$ns at 0.0 "$n1 label Receiver"

set nf [open snw.nam w]
$ns namtrace-all $nf

set f [open snw.tr w]
$ns trace-all $f

$ns duplex-link $n0 $n1 0.2Mb 200ms DropTail
$ns duplex-link-op $n0 $n1 orient right
$ns queue-limit $n0 $n1 10


Agent/TCP set nam_tracevar_ true


set tcp [new Agent/TCP]
$tcp set window_ 1
$tcp set maxcwnd_ 1
$ns attach-agent $n0 $tcp

set sink [new Agent/TCPSink]
$ns attach-agent $n1 $sink

$ns connect $tcp $sink

set ftp [new Application/FTP]
$ftp attach-agent $tcp

$ns add-agent-trace $tcp tcp
$ns monitor-agent-trace $tcp
$tcp tracevar cwnd_


$ns at 0.1 "$ftp start"
$ns at 3.0 "$ns detach-agent $n0 $tcp;$ns detach-agent $n1 $sink"
$ns at 3.5 "finish"


$ns at 0.0 "$ns trace-annotate \"Stop and Wait with normal operation\""

$ns at 0.5 "$ns trace-annotate \"FTP starts at 0.1\""

proc finish {} {
 global ns nf
        $ns flush-trace
        #Close the NAM trace file
        close $nf
        #Execute NAM on the trace file
        exec nam snw.nam &
        exit 0

} 

$ns run 
