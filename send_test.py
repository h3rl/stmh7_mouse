import socket

def send_udp_bytes(ip: str, port: int, data: bytes):
    # Create UDP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    try:
        # Send data
        sock.sendto(data, (ip, port))
        print(f"Sent {len(data)} bytes to {ip}:{port}")
    finally:
        sock.close()


# Example usage:
if __name__ == "__main__":
    ip = "192.168.82.1"   # Destination IP
    port = 5005           # Destination port
    data = bytes([1, 2, 3, 4, 5])  # Your byte array

    send_udp_bytes(ip, port, data)
